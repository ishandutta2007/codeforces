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

solve :: Int -> Int -> Int -> Bool
solve _ _ 0 = False
solve a b n = not $ solve b a (n - gcd a n)

main :: IO ()
main = do
        [a,b,n] <- getIntList
        putStrLn $ if solve a b n then "0" else "1"