# Bartek Kostka
#  You are not prepared!

import re


def go(i):
    global counter
    counter += 1
    if counter > 2000:
        return False
    if i == len(E):
        return True
    if E[i][0] != "?":
        prop = E[i][0]
        if i == 0 or W[i-1] != prop:
            W[i] = prop
            return go(i+1)
        else:
            return False
    for pos in E[i][1]:
        if i == 0 or W[i-1] != pos:
            W[i] = pos
            if go(i+1):
                return True
    return False


t = int(input())
for ttt in range(t):
    n = int(input())
    users = input().split(" ")
    users_set = set(users)
    m = int(input())
    E = []
    S = []
    counter = 0
    W = ["" for x in range(m)]
    for mmm in range(m):
        line = input()
        (user, sentence) = line.split(":")
        S.append((user, sentence))
        words = [x.strip() for x in re.split('\W+', sentence)]
        mentions = list(filter(lambda x: x in users_set, words))
        E.append([user, set(mentions)])
    for i in range(len(E)-1):
        if E[i][0] != "?":
            E[i+1][1].add(E[i][0])
    for i in range(1, len(E)):
        if E[i][0] != "?":
            E[i-1][1].add(E[i][0])
    for i in range(len(E)):
        E[i][1] = E[i][1].symmetric_difference(users_set)
    if go(0):
        for i in range(len(E)):
            print(str(W[i])+":"+str(S[i][1]))
    else:
        print("Impossible")