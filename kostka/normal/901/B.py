# -*- coding: utf-8 -*-

from itertools import izip
from math import fabs

def normalize(poly):
    while poly and poly[-1] == 0:
        poly.pop()
    if poly == []:
        poly.append(0)


def poly_div(num, den):
    #Create normalized copies of the args
    num = num[:]
    normalize(num)
    den = den[:]
    normalize(den)

    if len(num) >= len(den):
        #Shift den towards right so it's the same degree as num
        shiftlen = len(num) - len(den)
        den = [0] * shiftlen + den
    else:
        return [0], num

    quot = []
    divisor = den[-1]
    for i in xrange(shiftlen + 1):
        #Get the next coefficient of the quotient.
        mult = num[-1] / divisor
        quot = [mult] + quot

        #Subtract mult * den from num, but don't bother if mult == 0
        #Note that when i==0, mult!=0; so quot is automatically normalized.
        if mult != 0:
            d = [mult * u for u in den]
            num = [u - v for u, v in zip(num, d)]

        num.pop()
        den.pop(0)

    normalize(num)
    return quot, num

step = -1

def gcd(A, B):
    global step
    step += 1
    #print(A, B)
    if B == [0]:
       return A
    _, R = poly_div(A, B)
    return gcd(B, R)

W1 = [1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, -1, 0, -1, 0, 1, 0, 1, 0, 1, 0]
W2 = [1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, -1, 0, -1, 0, 1, 0, 1, 0, 1, 0]


if __name__ == '__main__':
    n = int(input())
    X = []
    for i in range(n+1):
        X.append(W1[i%len(W1)])
    X = list(reversed(X))
    Y = []
    for i in range(n):
        Y.append(W2[i%len(W2)])
    Y = list(reversed(Y))
    #print(X, Y)
    #gcd(X, Y)
    #print(step)
    print n
    for ele in X:
        print ele,
    print
    print n-1
    for ele in Y:
        print ele,