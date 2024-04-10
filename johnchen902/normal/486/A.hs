import Control.Monad
import Data.Array
import Data.Char
import Data.Int
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

-- theList :: [String]
-- theList = "Sheldon" : "Leonard" : "Penny" : "Rajesh" : "Howard" : concatMap (replicate 2) theList

solve :: Int64 -> Int64
solve n = if even n then n `div` 2 else -1 - (n `div` 2)

main :: IO ()
main = getLine >>= print . solve . read