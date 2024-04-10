import sys
from math import *

def win(a,b):
    if (a==0):
        return False
    if (b==0):
        return False
    if (not win(b%a,a)):
        return True
    ans=b//a
    ans%=a+1
    ans%=2
    if (ans%2==1):
        return False
    else:
        return True

try:
    fi = open("input.txt", "r")
    fo = open("output.txt", "w")
except:
    fi = sys.stdin
    fo = sys.stdout

tests=int(fi.readline())
for test in range(tests):
    a,b=map(int,fi.readline().split())
    if (win(min(a,b),max(a,b))):
        fo.write("First\n")
    else:
        fo.write("Second\n")