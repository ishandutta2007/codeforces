import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

islucky :: Int -> Bool
islucky 0 = True
islucky x = (x `mod` 10 == 4 || x `mod` 10 == 7) && islucky (x `div` 10)

solve :: Int -> Bool
solve x = any ((==0) . (x `mod`)) . filter islucky $ [1..x]

main :: IO ()
main = do
        n <- readLn
        putStrLn $ if solve n then "YES" else "NO"