import sys
from math import *


fi = sys.stdin ##open("input.txt","r") 
fo = sys.stdout ##open("output.txt","w") 


n=int(fi.readline())
cur=0
ans=0
for i in range(n):
    a,b=map(int,fi.readline().split())
    cur+=b-a
    ans=max(ans,cur)

fo.write(str(ans))