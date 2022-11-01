import Control.Monad
import Data.Array
import Data.Char
import Data.Functor
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = map (read . B.unpack) . B.words <$> B.getLine
getIntList :: IO [Int]
getIntList = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine

toD :: Int -> Double
toD = fromIntegral

solve :: Int -> [Int] -> Double
solve l a = max (toD (max (head sa) (l - last sa))) x
    where sa = sort a
          x  = (toD . maximum $ 0 : zipWith (-) (tail sa) sa) / 2

main :: IO ()
main = do
    [_, l] <- getIntList
    a <- getIntList
    print $ solve l a