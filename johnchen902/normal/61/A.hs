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

chxor :: Char -> Char -> Char
chxor a b = if a == b then '0' else '1'

solve :: String -> String -> String
solve = zipWith chxor

main :: IO ()
main = do
    s <- getLine
    t <- getLine
    putStrLn $ solve s t