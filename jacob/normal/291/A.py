from __future__ import print_function
from sys import stdin
from sys import exit

n = int(stdin.readline())

d = {}
for id in map(int, stdin.readline().split()):
    if (id != 0):
        d[id] = d.get(id, 0) + 1

if (not all(map(lambda x: (x == 2 or x == 1), d.values()))):
    print(-1)
    exit(0)

print(len([item for item in d.values() if item == 2]))