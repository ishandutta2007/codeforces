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

distinct :: Ord a => [a] -> Bool -- Eq a would be better
distinct = all ((==1) . length) . group . sort

solve :: Int -> Int
solve y = head $ filter (distinct . show) [y + 1..]

main :: IO ()
main = getLine >>= putStrLn . show . solve . read