import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

solve :: [Int] -> Int
solve a = (+1) . length . takeWhile (<= sum a `div` 2) . scanl1 (+) . sortBy (flip compare) $ a

main :: IO ()
main = do
        _ <- getLine
        a <- getIntList
        putStrLn . show $ solve a