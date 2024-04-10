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

solve :: Int -> Int -> Int -> Int
solve k n w = max 0 (w * (w + 1) `div` 2 * k - n)

main :: IO ()
main = do
        [k,n,w] <- getIntList
        putStrLn . show $ solve k n w