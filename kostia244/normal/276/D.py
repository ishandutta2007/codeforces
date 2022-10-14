from math import *
l, r = list(map(int, input().split(" ")))
print((2<<floor(log2(l^r)))-1 if l!=r else 0)