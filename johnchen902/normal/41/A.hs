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

solve :: String -> String -> Bool
-- solve s t = reverse s == t
solve = (==) . reverse

main :: IO ()
main = do
        s <- getLine
        t <- getLine
        putStrLn $ if solve s t then "YES" else "NO"