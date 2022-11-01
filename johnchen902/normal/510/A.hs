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

solve :: Int -> Int -> [String]
solve n m = take n $ cycle [replicate m '#',
                            replicate (m - 1) '.' ++ ['#'],
                            replicate m '#',
                            '#' : replicate (m - 1) '.']
                            

main :: IO ()
main = do
    [n, m] <- getIntList
    mapM_ putStrLn $ solve n m