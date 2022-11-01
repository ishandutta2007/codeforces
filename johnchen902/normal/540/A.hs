import Control.Monad
import Data.Array
import Data.Char
import Data.Functor
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = map (read . B.unpack) . B.words <$> B.getLine
getIntList :: IO [Int]
getIntList = unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine

moves :: Char -> Char -> Int
moves a b = min d (10 - d)
    where d = abs $ digitToInt a - digitToInt b

solve :: String -> String -> Int
solve s t = sum $ zipWith moves s t

main :: IO ()
main = do
    _ <- getLine
    s <- getLine
    t <- getLine
    print $ solve s t