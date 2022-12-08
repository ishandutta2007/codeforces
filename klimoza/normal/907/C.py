n = int(input())
will = [1 for i in range(26)]
bl = False
count = 0
for i in range(1, n + 1):
    s = input()
    if bl and s[0] != ".":
        count += 1
    elif i == n:
        count += 1
    else:
        act = s[0]
        word = s[2:]
        setta = set(word)
        if act == "!":
            for i in range(26):
                if str(chr(i + ord('a'))) not in setta:
                    will[i] = 0
            if sum(will) == 1:
                bl = True
        else:
            for i in range(26):
                if str(chr(i + ord('a'))) in setta:
                    will[i] = 0
            if sum(will) == 1:
                bl = True
count -= 1
print(count)