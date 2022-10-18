l = ['think', 'bad', 'touch', 'cool', 'great']
for i in range(6):
    print(i)
    s = input().lower()
    if any(x in s for x in l):
        print("normal")
        exit(0)
else:
    print("grumpy")