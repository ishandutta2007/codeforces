import sys
import math

N=int(input())
S=input().strip()
C=10**121212

mi=101010
for i in range(1,N):
	if S[i]!='0':
		mi=min(mi,max(i,N-i)+2)

for i in range(1,N):
	if S[i]!='0' and max(i,N-i)<=mi:
		T=int(S[0:i])+int(S[i:])
		C=min(C,T)

print(C)