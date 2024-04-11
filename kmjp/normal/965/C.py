import sys
import math

N,K,M,D=map(int,raw_input().strip().split(" "))

ma = 0
for i in range(1,D+1):
	ma = max(ma, min(M,N/(K*(i-1)+1))*i)

print ma