#!/usr/bin/python2.7

N, M = map(int, raw_input().split())

def solve(begin, end, M):
    if begin >= end: return []
    mid = 2**(end-begin-2)
    if M < mid:
        return [begin] + solve(begin+1, end, M)
    else:
        return solve(begin+1, end, M-mid) + [begin]

s = solve(1, N+1, M-1)
print ' '.join(map(str, s))