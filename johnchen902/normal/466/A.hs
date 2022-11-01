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

solve :: Int -> Int -> Int -> Int -> Int
solve n m a b = minimum [n * a, (n + m - 1) `div` m * b,
                         n `div` m * b + n `mod` m * a]

main :: IO ()
main = do
    [n, m, a, b] <- getIntList
    print $ solve n m a b