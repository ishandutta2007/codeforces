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

pass :: String -> String
pass [] = []
pass ('B':'G':t) = 'G' : 'B' : pass t
pass (h:t) = h : pass t

solve :: Int -> String -> String
solve n = (!! n) . iterate pass

main :: IO ()
main = do
        [_,t] <- getIntList
        s <- getLine
        putStrLn $ solve t s