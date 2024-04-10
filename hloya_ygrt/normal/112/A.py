def lower(s):
    n = len(s)
    t = ""

    for i in range(n):
        if s[i].isupper():
            x = ord(s[i])
            x = x - ord("A")
            x = x + ord("a")
            t = t + chr(x)
        else:
            t = t + s[i]
    return t

s1 = input()
t1 = lower(s1)
s2 = input()
t2 = lower(s2)

for i in range(len(t1)):
    if t1[i] < t2[i]:
        print(-1)
        exit(0)
    if (t2[i] < t1[i]):
        print(1)
        exit(0)

print(0)