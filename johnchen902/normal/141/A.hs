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

solve :: String -> String -> String -> Bool
solve s t u = sort (s ++ t) == sort u

main :: IO ()
main = do
    s <- getLine
    t <- getLine
    u <- getLine
    putStrLn $ if solve s t u then "YES" else "NO"