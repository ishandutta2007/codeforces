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

fight :: Int -> (Int, Int) -> Maybe Int
fight s (s', y') = if s <= s' then Nothing else Just (s + y')

solve :: Int -> [(Int, Int)] -> Bool
solve s = isJust . foldM fight s . sort

main :: IO ()
main = do
    [s, n] <- getIntList
    a <- replicateM n $ (\[x,y] -> (x, y)) <$> getIntList
    putStrLn $ if solve s a then "YES" else "NO"