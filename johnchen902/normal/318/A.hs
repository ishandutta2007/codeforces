import Control.Monad
import Data.Array
import Data.Char
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
-- import qualified Data.Text as T
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: Int64 -> Int64 -> Int64
solve n k = if k <= m then 2 * k - 1 else 2 * (k - m)
            where m = (n + 1) `div` 2

main :: IO ()
main = do
        [n,k] <- getList
        print $ solve n k