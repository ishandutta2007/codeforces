x = input()
lastletter = 'a'
used = set()
for i in range(len(x)):
    if x[i] not in used and x[i] != lastletter:
        print("NO")
        exit(0)
    elif x[i] == lastletter:
        lastletter = chr(ord(lastletter) + 1)
    used.add(x[i])
print("YES")