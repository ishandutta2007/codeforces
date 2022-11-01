import Control.Monad
import Data.Array
import Data.Char
import Data.Maybe
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: Int -> Int -> Int -> Int -> Int -> Int
solve k l m n d = length . filter damaged $ [1..d]
    where damaged :: Int -> Bool
          damaged x = x `mod` k == 0 || x `mod` l == 0 ||
                      x `mod` m == 0 || x `mod` n == 0

main :: IO ()
main = do
        k <- fmap read getLine
        l <- fmap read getLine
        m <- fmap read getLine
        n <- fmap read getLine
        d <- fmap read getLine
        putStrLn . show $ solve k l m n d