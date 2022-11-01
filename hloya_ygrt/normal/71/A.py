n = input()

for i in range(int(n)):
    s = input()
    if len(s) <= 10:
        print(s)
        continue
    t = s[0]
    t = t + str(len(s) - 2)
    t = t + s[len(s)-1]
    print(t)