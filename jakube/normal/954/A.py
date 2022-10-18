n = input()
path = input()

subs = 0
i = 0
while i < len(path) - 1:
    if path[i:i+2] in ("RU", "UR"):
        subs += 1
        i += 1
    i += 1

print(len(path) - subs)