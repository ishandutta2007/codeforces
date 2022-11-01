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

digits :: Show a => a -> [Int]
digits = map digitToInt . show

islucky :: Int -> Bool
islucky 4 = True
islucky 7 = True
islucky _ = False

solve :: Int64 -> Bool
solve = all islucky . digits . length . filter islucky . digits

main :: IO ()
main = do
        n <- fmap read getLine 
        putStrLn $ if solve n then "YES" else "NO"