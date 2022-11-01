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

tail' :: [a] -> Maybe [a]
tail' []    = Nothing
tail' (_:b) = Just b

findNot :: Char -> String -> Maybe String
findNot c = tail' . dropWhile (/=c)

solve :: String -> Bool
solve = isJust . foldl1 (>=>) (map findNot "hello")

main :: IO ()
main = do
        s <- getLine
        putStrLn $ if solve s then "YES" else "NO"