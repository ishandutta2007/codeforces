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
solve a b c = maximum [a + b + c, a * b * c, a * b + c, a + b * c, (a + b) * c, a * (b + c)]

main :: IO ()
main = do
        a <- fmap read getLine
        b <- fmap read getLine
        c <- fmap read getLine
        print $ solve a b c