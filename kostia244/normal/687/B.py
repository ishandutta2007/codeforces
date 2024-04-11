from math import *
from sys import *
n, k = map(int, stdin.readline().split(" "))
a = 1;
for c in map(int, stdin.readline().split(" ")):
  a = a * (gcd(k, c)//gcd(a, c))
if a%k == 0:
  print("Yes")
else:
  print("No")