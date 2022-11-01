import Control.Monad
import Data.Array
import Data.Char
import Data.Functor
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
-- import qualified Data.Text as T
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = map (read . B.unpack) . B.words <$> B.getLine
getIntList :: IO [Int]
getIntList = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine

dist :: Int -> Int -> Int -> Int
dist n a b = if b >= a then b - a else n + b - a

solve :: Int -> [Int] -> Int64
solve n a = sum $ map fromIntegral $ zipWith (dist n) (1:a) a

main :: IO ()
main = do
    [n, _] <- getIntList
    a <- getIntList
    print $ solve n a