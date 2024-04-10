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

maj :: [Bool] -> Bool
maj (True:True:_)   = True
maj (False:False:_) = False
maj (_:_:a:_)       = a
maj _ = error "WTF"

solve :: [Int] -> Int
solve = (+1) . fromJust . (elemIndex =<< not . maj) . map odd

main :: IO ()
main = do
    _ <- getLine
    a <- getIntList
    print $ solve a