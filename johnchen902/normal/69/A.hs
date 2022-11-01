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

solve :: [[Int]] -> Bool
solve = (==[0,0,0]) . foldl1 (zipWith (+))

main :: IO ()
main = do
        n <- fmap read getLine
        a <- replicateM n getIntList
        putStrLn $ if solve a then "YES" else "NO"