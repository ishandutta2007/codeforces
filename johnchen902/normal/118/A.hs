import Data.Char
-- import Data.Int
import Data.List
-- import Control.Monad
-- getList :: Read a => IO [a]
-- getList = fmap (map read . words) getLine

solve :: String -> String
solve = ('.':) . intersperse '.' . filter (flip notElem "aoeuiy") . map toLower

main :: IO ()
main = do
        s <- getLine
        putStrLn $ solve s