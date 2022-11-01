import re

options = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
input()
matcher = re.compile('^' + input().strip() + '$')
for a in options:
    if matcher.search(a) is not None:
        print(a)
        break