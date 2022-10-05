import sys
import math

N=input()
A=map(int,raw_input().strip().split(" "))

C={}
ret = S = 0
for i in range(N-1,-1,-1):
	ret += S-(N-1-i)*A[i]
	ret -= C.get(A[i]+1,0)
	ret += C.get(A[i]-1,0)
	S += A[i]
	C[A[i]] = C.get(A[i],0)+1

print(ret)