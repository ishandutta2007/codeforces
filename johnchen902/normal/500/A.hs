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

solve :: Int -> [Int] -> Bool
solve 1 _  = True
solve _ [] = False
solve t a@(h:_) = t >= 1 && solve (t - h) (drop h a)

main :: IO ()
main = do
        [_, t] <- getIntList
        a <- getIntList
        putStrLn $ if solve t a then "YES" else "NO"