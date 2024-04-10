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

theSeq :: [Int]
theSeq = scanl1 (+) (scanl1 (+) [1..])

solve :: Int -> Int
solve = fromJust . flip findIndex theSeq . (<)

main :: IO ()
main = do
    n <- read <$> getLine
    print $ solve n