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

solve :: Int -> [Int] -> Int
solve n = minimum . (zipWith subtract `ap` drop (n - 1)) . sort

main :: IO ()
main = do
        [n, _] <- getIntList
        a <- getIntList
        print $ solve n a