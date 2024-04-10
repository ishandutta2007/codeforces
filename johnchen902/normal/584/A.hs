import Control.Monad
import Data.Array
import Data.Char
import Data.Functor
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = map (read . B.unpack) . B.words <$> B.getLine
getIntList :: IO [Int]
getIntList = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine

-- best result only selecting numbers <= i
solve :: Integer -> Integer -> Integer
solve 1 10 = -1
solve n t = base + (t - base `mod` t)
    where base = 10 ^ (n - 1)

main :: IO ()
main = do
    [a, b] <- getIntList
    print $ solve (toInteger a) (toInteger b)