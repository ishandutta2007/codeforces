import Control.Monad
import Data.Array
import Data.Char
import Data.Maybe
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: [[Int]] -> Int
solve arr = abs (a - 2) + abs (b - 2)
    where a    = fromJust $ findIndex (elem 1) arr
          arr0 = fromJust $ find (elem 1) arr
          b    = fromJust $ elemIndex 1 arr0

main :: IO ()
main = replicateM 5 getIntList >>= putStrLn . show . solve