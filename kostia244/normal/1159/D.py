from math import *
from fractions import *
def li():
  return list(map(int, input().split(" ")))
n,k = li()
if k == 1:
  print("1" + "0"*(n-1))
else:
  a = (n-k)//2
  p = "1" + "0"*a
  ans = p * (n//(a+1)) + p[:(n%(a+1))]
  print(ans)