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
solve a = g4 + g3 + (g2 + 1) `div` 2 + max 0 (g1 - g3 - g2 `mod` 2 * 2 + 3) `div` 4
    where cnt = accumArray (+) 0 (1,4) $ zip a (repeat 1)
          g4 = cnt ! 4
          g3 = cnt ! 3
          g2 = cnt ! 2
          g1 = cnt ! 1

main :: IO ()
main = do
        _ <- getLine -- n
        a <- getIntList
        putStrLn . show $ solve a