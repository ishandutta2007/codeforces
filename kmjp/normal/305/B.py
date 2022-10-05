import sys

def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)

P,Q=map(int,raw_input().split(" "))
G=gcd(P,Q)
P/=G
Q/=G

N=input()
A=map(int,raw_input().split(" "))

TP=1
TQ=0
for x in range(N):
    y=N-1-x
    TP,TQ=TQ,TP
    TP+=TQ*A[y]

G=gcd(TP,TQ)
TP/=G
TQ/=G

if P==TP and Q==TQ:
    print("YES")
else:
    print("NO")