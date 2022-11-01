import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

accident :: String -> Bool
accident = all isUpper . tail

flipcase :: Char -> Char
flipcase c = if isLower c then toUpper c else toLower c

solve :: String -> String
solve s = if accident s then map flipcase s else s

main :: IO ()
main = getLine >>= putStrLn . solve