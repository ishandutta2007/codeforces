import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: String -> String
solve = liftM2 (:) (toUpper . head) tail

main :: IO ()
main = getLine >>= putStrLn . solve