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

solve1 :: (Int -> Int -> Bool) -> [Int] -> Int
solve1 _ [] = 0
solve1 f (h:t)  = 1 + solve1 f (dropWhile (f h) t)

solve :: [Int] -> Int
solve = subtract 2 . liftM2 (+) (solve1 (<=)) (solve1 (>=))

main :: IO ()
main = getLine >> getIntList >>= print . solve