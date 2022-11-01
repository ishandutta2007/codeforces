#!/usr/bin/python

a = sum(map(int, raw_input().split()))
if a % 5 == 0 and a != 0:
    print a / 5
else:
    print -1