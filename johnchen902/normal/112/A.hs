import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: String -> String -> Int
solve s t = case map toLower s `compare` map toLower t of
                GT -> 1
                EQ -> 0
                LT -> -1

main :: IO ()
main = do
        s <- getLine
        t <- getLine
        putStrLn . show $ solve s t