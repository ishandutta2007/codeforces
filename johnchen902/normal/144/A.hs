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

solve :: [Int] -> Int
solve a = maxH + (n - 1 - minL) + (if maxH < minL then 0 else -1)
    where n    = length a
          maxi = maximum a
          mini = minimum a
          maxH = head $ elemIndices maxi a
          minL = last $ elemIndices mini a

main :: IO ()
main = do
        _ <- getLine
        a <- getIntList
        print $ solve a