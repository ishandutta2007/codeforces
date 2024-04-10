i = int(0)
j = int(0)

while i < 5:
    s = input()
    j = int(0)
    ans = 0
    while j < 10:
        if s[j] == '1':
            ans = 1
            break
        j = j + 2
    if ans == 1:
        print(abs(2-i) + abs(2 - int(j/2)))
        exit(0)
    i = i + 1