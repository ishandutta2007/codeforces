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

solve :: String -> String
solve s = map (if morel then toLower else toUpper) s
    where morel = length (filter isLower s) >=
                  length (filter isUpper s)

main :: IO ()
main = getLine >>= putStrLn . solve