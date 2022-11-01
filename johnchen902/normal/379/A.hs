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

solve :: Int -> Int -> Int
solve a b = a + (a - 1) `div` (b - 1)

main :: IO ()
main = do
        [a,b] <- getIntList
        print $ solve a b