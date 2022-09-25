import sys
from math import *

try:
    fi = open("input.txt", "r")
    fo = open("output.txt", "w")
except:
    fi = sys.stdin
    fo = sys.stdout
 
n,k=map(int,fi.readline().split())
a=[0 for i in range(n)]
b=[0 for i in range(n)]

for i in range(n):
    a[i],b[i]=map(int,fi.readline().split())

for i in range(n-1):
    for j in range(n-i-1):
        if ((a[j]<a[j+1]) | ((a[j]==a[j+1]) & (b[j]>b[j+1]))):
            x=a[j]
            a[j]=a[j+1]
            a[j+1]=x
            x=b[j]
            b[j]=b[j+1]
            b[j+1]=x
ans=0
for i in range(n):
    ans+=(a[i]==a[k-1])&(b[i]==b[k-1])
fo.write(str(ans))