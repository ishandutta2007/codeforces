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

solve :: [[Int]] -> Int
solve a = length [() | i <- a, j <- a, head i == j !! 1]

main :: IO ()
main = do
        n <- read <$> getLine
        a <- replicateM n getIntList
        print $ solve a