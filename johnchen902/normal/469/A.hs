import Control.Monad
import Data.Array
import Data.Char
import Data.Int
import Data.List
import Data.List.Split
import Data.Maybe
-- import qualified Data.Text as T
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: Int -> [Int] -> [Int] -> Bool
-- solve lv a b = all (liftM2 (||) (`elem` a) (`elem` b)) [1..lv]
solve lv a b = (==[1..lv]) . map head . group . sort $ a ++ b

main :: IO ()
main = do
        lv <- fmap read getLine
        a  <- fmap tail getIntList
        b  <- fmap tail getIntList
        putStrLn $ if solve lv a b then "I become the guy." else "Oh, my keyboard!"